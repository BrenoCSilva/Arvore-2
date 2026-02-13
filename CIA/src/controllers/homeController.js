const Arvore = require("../models/arvoreModel");


exports.index = async(req, res) => {

        const arvores = await Arvore.buscaArvores();
        res.render("index", {arvores});
}

