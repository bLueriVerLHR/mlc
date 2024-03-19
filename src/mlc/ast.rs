use pest::iterators::Pairs;

use super::parser::Rule;

pub fn build_ast(semi_tree: Pairs<'_, Rule>) {
    println!("{:#?}", semi_tree);
}