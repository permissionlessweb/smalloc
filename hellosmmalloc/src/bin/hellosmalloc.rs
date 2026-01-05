use smmalloc::Smmalloc;
#[global_allocator]
static ALLOC: Smmalloc = Smmalloc::new();

pub fn main() {
    println!("Hello, world! I'm smmalloc. :-)");

    const NUM_ELEMS: usize = 9999;

    let vu8s: Vec<u8> = vec![7; NUM_ELEMS];
    let vu128s: Vec<u128> = vec![11; NUM_ELEMS];

    const I: usize = 7777;

    println!("vu8s[{}] = {}", I, vu8s[I]);
    println!("vu128s[{}] = {}", I, vu128s[I]);
}
