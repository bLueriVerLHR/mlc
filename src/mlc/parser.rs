use pest_derive::Parser;
use pest::{iterators::Pairs, Parser};

#[derive(Debug, Parser)]
#[grammar = "SysY2022.pest"]
struct SysY2022;

pub fn parse_file(raw_text: &str) -> Pairs<'_, Rule> {
    SysY2022::parse(Rule::CompUnit, raw_text).unwrap_or_else(|e| panic!("{}", e))
}