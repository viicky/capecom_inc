#include "vueaccueil.h"
#include "garage.h"
#include <QBoxLayout>

#include "garage.h"


VueAccueil::VueAccueil(Garage& g, QWidget *parent): QWidget(parent), Vue(g)
{

    QVBoxLayout *layoutFen = new QVBoxLayout(); //layout global
    QHBoxLayout *layoutActeurs = new QHBoxLayout();
    QVBoxLayout *layoutCas = new QVBoxLayout();
    layoutFen->addLayout(layoutActeurs);
    layoutFen->addLayout(layoutCas);

    btnAdmin = new QRadioButton("admin");
    btnAjouterVehicule = new QPushButton("Ajouter véhicule");
    btnSupprimerVehicule = new QPushButton("Supprimer véhicule");
    btnAjouterLocation = new QPushButton("Ajouter location");

    layoutActeurs->addWidget(btnAdmin);
    layoutCas->addWidget(btnAjouterVehicule);
    layoutCas->addWidget(btnSupprimerVehicule);
    layoutCas->addWidget(btnAjouterLocation);

    this->setLayout(layoutFen);

    QObject::connect(btnAjouterVehicule, SIGNAL(clicked()), this, SLOT(ajouterVehicule()));
    QObject::connect(btnSupprimerVehicule, SIGNAL(clicked()), this, SLOT(supprimerVehicule()));
    QObject::connect(btnAjouterLocation,SIGNAL(clicked()), this, SLOT(ajouterLocation()));
    garage->ajouterVue(*this);
}


void VueAccueil::ajouterVehicule(){
    garage->setCasUtilisation(Garage::AJOUTER_VEHICULE);
}

void VueAccueil::supprimerVehicule(){
    garage->setCasUtilisation(Garage::SUPPRIMER_VEHICULE);
}

void VueAccueil::ajouterLocation(){
    garage->setCasUtilisation(Garage::AJOUTER_LOCATION);
}

void VueAccueil::maj(){
    std::cout<< "maj de vue accueil\n";
}
