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

	std::string getEmail();
	std::string getContrasenia();

	void setEmail(std::string _email);
	void setContrasenia(std::string _contrasenia);

	virtual ~Usuario();
};

#endif /* USUARIO_H */
