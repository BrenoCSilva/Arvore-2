exports.middlewareGlobal = (req, res, next) => {
    res.locals.erros = req.flash("erros");
    res.locals.sucessos = req.flash("sucessos");
    res.locals.user = req.session.user;
    console.log("Passei no middleware global");
    next();
};


exports.loginRequired = (req, res, next) =>{
    
    if(!req.session.user){

        req.flash("erros", "Você precisa fazer login");
        req.session.save(()=>{
            res.redirect("/");
        });

        return;
    }

    next();

};