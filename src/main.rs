use clap::Parser;
use std::fs;
use std::io;
use std::io::ErrorKind;

#[derive(Parser, Debug)]
#[clap(author, version, about, long_about = None)]
struct Args {
    #[clap(short, long, value_parser, conflicts_with = "filename")]
    code: Option<String>,
    #[clap(short, long, value_parser, required_unless = "code")]
    filename: Option<String>,
}

fn get_code(args: Args) -> io::Result<String> {
    match args.filename {
        Some(x) => return fs::read_to_string(x),
        None => (),
    }

    match args.code {
        Some(x) => return Ok(x),
        None => return Err(io::Error::from(ErrorKind::InvalidInput)),
    }
}

fn main() {
    let args = Args::parse();
    let code = get_code(args);

    match code {
        Ok(x) => println!("Code = {}", x),
        Err(error) => println!("Error loading input, {}", error),
    }
}
