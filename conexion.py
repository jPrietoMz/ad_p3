import subprocess

comando = "C:\\Users\\JOSE7PM\\Documents\\GitHub\\ad_p3\\jvdb.exe insert miempresa clientes cliente4 'este es el cliente 4'"
resultado = subprocess.run(comando, shell=True, stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)

if resultado.returncode == 0:
    print ("ok")
else:
    print("ko")
    
