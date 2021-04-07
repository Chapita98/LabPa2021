#ifndef BARCOPESQUERO_H
#define BARCOPESQUERO_H


class BarcoPesquero : public Barco
{
	private:
		int Capacidad;
		int Carga;

	public:
		BarcoPesquero(int capacidad, int carga);
		BarcoPesquero(int capacidad, int carga, std::string nombre, std::string id);

		int getCapacidad() const;
		int getCarga() const;

		void setCapacidad(int capacidad);
		void setCarga(int carga);

		virtual ~BarcoPesquero();
};

#endif /* BARCOPESQUERO_H */
