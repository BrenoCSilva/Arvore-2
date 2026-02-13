const mongoose = require("mongoose");
const validator = require("validator");
const bcryptjs = require("bcryptjs")

const LoginSchema = new mongoose.Schema({
    email: { type: String, required: true },
    password: { type: String, required: true }
});

const LoginModel = mongoose.model("Login", LoginSchema);


class Login {

    constructor(body) {

        this.body = body;
        this.erros = [];
        this.user = null;
    }

    async login() {

        this.valida(); 
        if (this.erros.length > 0) return; 

        this.user = await LoginModel.findOne({email: this.body.email});
        
        //confirma se ao logar o usuario existe
        if(!this.user){
            this.erros.push("Usuário não existe.");
            return;
        }

        //usuario existindo confirma se voce digitou a senha corretamente, senha digita x senha do hash do BD
        if(!bcryptjs.compareSync(this.body.password, this.user.password)){
            this.erros.push("Senha inválida");
            this.user=null; // confirmando que o usuario vai ser nulo
            return;
        }

    }

    async register() {

        this.valida(); // vai validar os campos de email e senha se houver erro ele coloca no atributo this.erros

        if (this.erros.length > 0) return; // se o atributo de login tiver mais de um erro retorna

        await this.userExistencia();

        if (this.erros.length > 0) return; 

        const salt = bcryptjs.genSaltSync();
        this.body.password = bcryptjs.hashSync(this.body.password, salt);
        
        this.user = await LoginModel.create(this.body);
    
    }

    async userExistencia(){
        this.user = await LoginModel.findOne({email: this.body.email});
        if(this.user) this.erros.push("Usuário já existe.");
    }

    valida() {

        this.cleanUp();

        // validacao do email

        if (!validator.isEmail(this.body.email)) this.erros.push("Email inválido");

        // senha entrre 3 e 50 caracteres

        if (this.body.password.length < 3 || this.body.password.length > 50) {
            this.erros.push("A senha precisa ter entre 3 e 50 caracteres.");
        }

    }

    cleanUp() {
        //garantir que tudo que vim do body eh string
        for (const key in this.body) {
            if (typeof this.body[key] !== "string") {
                this.body[key] = "";
            }
        };

        // garantir que objeto body do Login so tenha os atributos necessarios
        this.body = {

            email: this.body.email,
            password: this.body.password
        };
    };

}

module.exports = Login;