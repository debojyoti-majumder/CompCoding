class SimpleMessage {
    constructor(msg, rep) {
        this.msg = msg;
        this.rep = rep;
    }

    get repetation() {
        return this.rep;
    }

    set repetation(newVal) {
        this.rep = newVal;
    }

    get printableString() {
        let str = "";

        for(var i=0; i<this.rep; i++) {
            str += this.msg;

            if( i != this.rep - 1)
                str +=";";
        }

        return str;
    }
}

module.exports.SimpleMessage = SimpleMessage;
