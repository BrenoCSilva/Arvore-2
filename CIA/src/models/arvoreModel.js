const mongoose = require("mongoose");

const ArvoreSchema = new mongoose.Schema({
    nome: { type: String, required: true },
    copa: { type: String, required: true },
    origem: { type: String, required: true },
    bioma: { type: String, required: true },
    temFrutos: {type: Boolean, default: false},
    porte: {type: String, enum:["baixo", "medio", "alto"], required: true},
    mesesFruto: {type:[String], default: []},
    mesesFlor: {type:[String], default: []},
    criadoEm: {type: Date, default: Date.now},
    rfid_uid: {type: String, default:"CF877841"}
    
});

const ArvoreModel = mongoose.model("Arvore", ArvoreSchema);


class Arvore{

    constructor(body) {

        this.body = body;
        this.erros = [];
        this.arvore = null;
    }


    async register(){

        this.valida();

        if(this.erros.length > 0) return;

        await this.arvoreExistencia();

        if(this.erros.length > 0) return;


        this.arvore = await ArvoreModel.create(this.body);


    }


    async arvoreExistencia(){

        this.arvore = await ArvoreModel.findOne({nome: this.body.nome});
        if(this.arvore) this.erros.push("Árvore já existe.");
    }


    valida() {

        this.cleanUp();
        

        if(!this.body.nome){
            this.erros.push("Nome é um campo obrigatório.");
        }
        
        if(!this.body.copa){
            this.erros.push("Copa é um campo obrigatório.");
        }

        if(!this.body.origem){
            this.erros.push("País de origem é um campo obrigatório.");
        }

        if(!this.body.bioma){
            this.erros.push("Bioma é um campo obrigatório.");
        }


        // conversao dos dados coletados para o padrao SCHEMA do DB
        
        this.body.temFrutos = (this.body.temFrutos === 'sim'); // retorna um boolean: true se "sim" e false caso sejam diferentes
        
        this.body.mesesFruto = (this.body.mesesFruto || []); // se o array mesesFruto for vazio ele sera undefined e isso no || é false então ele manda o [] se nao for undefined e ele contiver uma lista ["janeiro"] ele já manda essa 
    
        this.body.mesesFlor = (this.body.mesesFlor || []);
    
    }



    cleanUp() {

        //garantir que tudo que  vim do body eh string
        for (const key in this.body) {
            // Se a chave for mesesFruto ou mesesFlor, sera um "array" nao limpe o dado
            if (key === 'mesesFruto' || key === 'mesesFlor') continue;

            if (typeof this.body[key] !== "string") {
                this.body[key] = "";
            }
        };

        // garantir que objeto body do Login so tenha os atributos necessarios
        this.body = {

            nome: this.body.nome,
            copa: this.body.copa,
            origem: this.body.origem,
            bioma: this.body.bioma,
            temFrutos: this.body.temFrutos,
            porte: this.body.porte,
            mesesFruto: this.body.mesesFruto,
            mesesFlor: this.body.mesesFlor
        };
    };

    
     async edit(id){

        if(typeof id !== "string") return;
        this.valida();
        if(this.erros.length > 0) return;

        this.arvore = await ArvoreModel.findByIdAndUpdate(id, this.body, {new: true});

    }

    // metodos estaticos

    static async buscaArvores(){

        const arvores = await ArvoreModel.find()
            .sort({criado: -1});

        return arvores;

    }

    static async buscaPorId(id){

        if(typeof id !== "string") return;
        
        const arvore = await ArvoreModel.findById(id);
        return arvore;
    }


    static async delete (id){
        if(typeof id !== "string") return;
        const arvore = await ArvoreModel.findByIdAndDelete(id);
        return arvore;
    }

    static async buscaPorUid(uid) {
        if (typeof uid !== 'string') return null;
        
        // Aqui dentro usamos o ArvoreModel (o Mongoose)
        const arvore = await ArvoreModel.findOne({ rfid_uid: uid });
        return arvore;
    }
};



module.exports = Arvore;

