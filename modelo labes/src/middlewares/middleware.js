exports.middlewareGlobal = (req, res, next) => {
    res.locals.erros = req.flash("erros");
    console.log("Passei no middleware global");

    next();
}


exports.outroMiddleware = (req, res, next) => {

    console.log("Outro no middleware global");

    next();
}