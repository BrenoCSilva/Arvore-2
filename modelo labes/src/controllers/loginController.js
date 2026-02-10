const Login = require("../models/loginModel");

exports.index = (req, res) => {

    res.render("login");

}


exports.register = async (req, res) => {
    const login = new Login(req.body);
    await login.register();

    if (login.erros.length > 0) {

        req.flash("erros", login.erros);
        req.session.save(() => {
            //  return res.redirect("back");
            return res.redirect("/login");
            console.log("ERROR")
        });
        return;
    }
    // Se deu tudo certo
    req.flash("success", "Seu usuário foi criado com sucesso.");
    req.session.save(() => {
        return res.redirect("/login");
    });

    // Remova o res.send(login.erros);
    //res.send(login.erros);

}