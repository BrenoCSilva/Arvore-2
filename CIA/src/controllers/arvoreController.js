const Arvore = require("../models/arvoreModel");

exports.index = async(req, res) =>{

    res.render("arvore", {arvore: {}});
}


exports.register = async (req, res) =>{

    try{

        const arvore = new Arvore(req.body);
        await arvore.register();

       if (arvore.erros.length > 0) {

            req.flash("erros", arvore.erros);
            req.session.save(() => {
                return res.redirect("/arvore/index");
            });
            return;
        }
        
        req.flash("sucessos", "Sua árvore foi criada com sucesso.");
        req.session.save(() => {
            return res.redirect("/arvore/index");
        });
    
    }catch(e){
        res.render("404");
        console.log(e);
    }

}


exports.editIndex = async (req, res) => {

     console.log("index")

    if(!req.params.id) return res.render("404");

    const arvore = await Arvore.buscaPorId(req.params.id);
console.log("index")
    if(!arvore) return res.render("404");
    res.render("arvore", {arvore});


}




exports.edit = async (req, res) => {

    try{

        console.log("Chegie")
        if(!req.params.id) return res.render("404");

        const arvore = new Arvore(req.body);
        await arvore.edit(req.params.id);

        if (arvore.erros.length > 0) {

            req.flash("erros", arvore.erros);
            req.session.save(() => {
                return res.redirect("/arvore/index");
            });
            return;
        }
        
        req.flash("sucessos", "Sua árvore foi editada com sucesso.");
        req.session.save(() => {
            return res.redirect("/arvore/index");
        });
    
    }catch(e){
        res.render("404");
        console.log(e);
    }

}   


exports.delete = async (req, res) => {

    if(!req.params.id) return res.render("404");

    const arvore = await Arvore.delete(req.params.id);

    if(!arvore) return res.render("404");

    req.flash("sucessos", "Árvore apagada com sucesso");
    req.session.save(()=>{
        res.redirect("/");
    });

    return;
};



exports.getArvoreJson = async (req, res) => {
    try {
        const arvore = await Arvore.buscaPorUid(req.params.uid);
        
        if (!arvore) {
            return res.status(404).json({ erro: "Árvore não encontrada" });
        }

        // Retorna os dados no formato que o seu ESP32 já sabe ler
        res.json(arvore);
    } catch (e) {
        res.status(500).json({ erro: "Erro no servidor" });
    }
};