use std::fs::{read_to_string, write};

use super::{ast::build_ast, parser::parse_file};

pub struct Compiler {
    fin: String,
    fout: String,
    
    // currently support 0 1
    olv: u8,

    // asm ast llvm
    emit: (bool, bool, bool),
}

impl Compiler {
    pub fn new(fin: String, fout: String, olv: u8, emit: (bool, bool, bool)) -> Compiler {
        Compiler { fin, fout, olv, emit }
    }

    pub fn run(&self) {
        let text = read_to_string(&self.fin).unwrap();
        let semi_tree = parse_file(text.as_str());
        build_ast(semi_tree);

        let text = text;
        write(&self.fout, text).unwrap();
    }
}
