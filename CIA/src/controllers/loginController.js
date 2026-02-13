const Login = require("../models/loginModel");

exports.index = (req, res) => {

    if(req.session.user){
        res.render("login-logado");
        return;
    }
    
    return res.render("login");
   

}


exports.register = async (req, res) => {
    
    try{

        const login = new Login(req.body);
        await login.register();

        if (login.erros.length > 0) {

            req.flash("erros", login.erros);
            req.session.save(() => {
                return res.redirect("/login");
            });
            return;
        }
        
        req.flash("sucessos", "Seu usuário foi criado com sucesso.");
        req.session.save(() => {
            return res.redirect("/login");
        });
    
    }catch(e){
        res.render("404");
        console.log(e);
    }
}



exports.login = async (req, res) => {
    
    try{
        const login = new Login(req.body);
        await login.login();

        if (login.erros.length > 0) {

            req.flash("erros", login.erros);
            req.flash("sucessos", "Douglas");
            req.flash("erros", login.erros);
            req.flash("sucessos", "Douglas");
            req.session.save(() => {
                return res.redirect("/login");
            });
            return;
        }
        
        req.flash("sucessos", "Você entrou no sistema.");
        req.session.user = login.user;
        req.session.save(() => {
            return res.redirect("/login");
        });
    
    }catch(e){
        res.render("404");
        console.log(e);
    }
}

exports.logout = (req, res) => {
    req.session.destroy();
    res.redirect("/");

}