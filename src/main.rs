use clap::Parser;

#[derive(Parser, Debug)]
#[clap(author, version, about, long_about = None)]
struct Args {
    #[clap(short, long, value_parser, conflicts_with = "filename")]
    code: Option<String>,
    #[clap(short, long, value_parser, required_unless = "code")]
    filename: Option<String>,
}

fn main() {
    let args = Args::parse();
    match args.code {
        Some(x) => println!("Code: {x}"),
        None    => ()
    }
    match args.filename {
        Some(x) => println!("Filename: {x}"),
        None    => ()
    }
}
