from jvdb_conector import Ad_p3

Conexion1 = Ad_p3("miempresa")
Resultado_update= Conexion1.update("clientes","cliente15","Pablo")
print(Resultado_update)
                
 
