from Cypto.Cipher import DES
from Crypto.Util.Padding import pad

key=bytes(input("Enter key :"),'utf-8')
text=bytes(input("Enter message :"),'utf-8')

enc_txt=DES.new(key,DES.MODE_ECB).encrypt(pad(text,DES.block_size))
dec_txt=DES.new(key,DES.MODE_ECB).decrypt(enc_txt)

print("Encrypted text.." ,enc_txt) 
print("Decrypted text..",dec_txt[:len(text)])
