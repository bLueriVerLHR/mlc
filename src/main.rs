extern crate clap;
extern crate pest;
extern crate pest_derive;

pub mod mlc;

use clap::Parser;

use crate::mlc::compiler::Compiler;

#[derive(Parser, Debug)]
#[command(version, about, long_about = None)]
struct CmdArgs {
    /// input file name
    input: String,

    /// output file name
    #[arg(short = 'o', default_value_t = String::from("main"))]
    output: String,

    /// Optimization level
    #[arg(short = 'O', default_value_t = 0)]
    optimization: u8,

    /// output asm file
    #[arg(short = 'S', default_value_t = false)]
    asm: bool,

    /// output ast file
    #[arg(long = "emit-ast", default_value_t = false)]
    emit_ast: bool,

    /// output llvm file
    #[arg(long = "emit-llvm", default_value_t = false)]
    emit_llvm: bool,
}

fn main() {
    let args = CmdArgs::parse();
    println!("{:#?}", args);

    Compiler::new(
        args.input,
        args.output,
        args.optimization,
        (args.asm, args.emit_ast, args.emit_llvm),
    ).run();
}
