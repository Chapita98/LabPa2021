#ifndef BARCOPESQUERO_H
#define BARCOPESQUERO_H


class BarcoPesquero : public Barco {
	public:
	    BarcoPesquero()
		BarcoPesquero(int Capacidad, int Carga);
		int getCapacidad() const;
		int getCarga() const;
		void setCapacidad(int Capacidad);
		void setCarga(int Carga);

        virtual ~BarcoPesquero();
        virtual void Arribar(float cargaDespacho) override;

	private:
		int Capacidad;
		int Carga;
};

#endif /* BARCOPESQUERO_H */
