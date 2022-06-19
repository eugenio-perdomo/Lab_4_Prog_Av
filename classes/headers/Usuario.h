#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "./../../ICollection/interfaces/ICollection.h"

class Usuario : public ICollectible
{
protected:
	std::string email;
	std::string contrasenia;

public:
	Usuario();
	Usuario(std::string _email, std::string _contrasenia);

	std::string getEmail(){ return email; }
	std::string getContrasenia(){ return contrasenia; }
	void setEmail(std::string val){ email = val; }
	void setContrasenia(std::string val){ contrasenia = val; }

	virtual ~Usuario();
};

#endif /* USUARIO_H */
