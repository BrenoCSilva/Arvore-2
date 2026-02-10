const HomeModel = require("../models/homeModels");
/*
HomeModel.create({
        titulo: "Testando banco de dados",
        descricao: "descricao"
})
.then(dados => console.log(dados))
.catch(e => console.log(e));
*/
exports.index = (req, res) => {
        res.render("index");
}


exports.post = (req, res) => {

        console.log("Testando rota de post");
        res.send("Testando rota de post");

}