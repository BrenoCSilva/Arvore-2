const mongoose = require("mongoose");
const validator = require("validator");

const LoginSchema = new mongoose.Schema({
    email: { type: String, required: true },
    senha: { type: String, required: true }
});

const LoginModel = mongoose.model("Login", LoginSchema);


class Login {

    constructor(body) {

        this.body = body;
        this.erros = [];
        this.user = null;
    }

    async register() {

        this.valida();

        if (this.erros.length > 0) return;

        try {
            this.user = await LoginModel.create(this.body);
        }
        catch (e) {
            console.log(e);
            this.erros.push("Erro ao cadastrar no banco de dados (Verifique a conexão).");
        }
    }

    valida() {

        this.cleanUp();

        // validacao do email

        if (!validator.isEmail(this.body.email)) this.erros.push("Email invalido");

        // senha entrre 3 e 50 caracteres

        if (this.body.password.length < 3 || this.body.password.length > 50) {
            this.erros.push("A senha precisa ter entre 3e 50 caracteres.");
        }

    }

    cleanUp() {

        for (const key in this.body) {
            if (typeof this.body[key] !== "string") {
                this.body[key] = "";
            }
        };


        this.body = {

            email: this.body.email,
            password: this.body.password
        };
    };

}

module.exports = Login;