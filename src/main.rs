extern crate clap;

use clap::Parser;

#[derive(Parser, Debug)]
struct CmdArgs {
    /// output file name
    #[arg(short = 'o', default_value_t = String::new())]
    output: String,

    /// Optimization level
    #[arg(short = 'O', default_value_t = 0)]
    optimization: u8,

    /// output asm file
    #[arg(short = 'S', default_value_t = false)]
    asm: bool
}

fn main() {
    let args = CmdArgs::parse();
    println!("{:?}", args);
}