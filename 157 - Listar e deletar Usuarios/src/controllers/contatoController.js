const Contato = require("../models/contatoModel");


exports.index = (req, res) => {

    //res.render("contato");
    res.render('contato', {
        contato: {} 
    });
}

exports.register = async (req, res) => {

    try{
        const contato = new Contato(req.body);
        
        await contato.register();

        if(contato.erros.length > 0){

            req.flash('erros', contato.erros);
            req.session.save(()=>{
                res.redirect("/contato/index");
            });

            return;
        };

        req.flash('sucessos', "Contato registrado com suceso!");
        req.session.save(()=>{
            res.redirect(`/contato/index/${contato.contato.id}`);
        });
    }

    catch(e){
        console.log(e);
        res.render("404");
    }
}


exports.editIndex = async (req, res) =>{
    if(!req.params.id) return res.render("404");

    const contato = await Contato.buscaPorId(req.params.id);

    if(!contato) return res.render("404");
    res.render("contato", {contato});

};


exports.edit = async (req, res) => {

    try{

    
       if(!req.params.id) return res.render("404");

        const contato = new Contato(req.body);
        await contato.edit(req.params.id);


        if(contato.erros.length > 0){

            req.flash('erros', contato.erros);
            req.session.save(()=>{
                res.redirect("/contato/index");
            });

            return;
        };

        req.flash('sucessos', "Contato editado com suceso!");
        req.session.save(()=>{
            res.redirect(`/contato/index/${contato.contato.id}`);
        });
    }
    catch (e){
        console.log(e);
         res.render("404");
    }
};


exports.delete = async (req, res) => {

    if(!req.params.id) return res.render("404");

    console.log("/passii");
    const contato = await Contato.delete(req.params.id);

    if(!contato) return res.render("404");

    req.flash("sucessos", "Contato apagado com sucesso");
    req.session.save(()=>{
        res.redirect("/");
    });

    return;
};