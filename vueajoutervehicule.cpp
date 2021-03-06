#include "vueajoutervehicule.h"
#include "garage.h"
#include <QFormLayout>
#include <QHBoxLayout>

#include "Voiture.hpp"
#include "velo.h"
#include "bus.h"


VueAjouterVehicule::VueAjouterVehicule(Garage& g, QWidget* parent): QWidget(parent), Vue(g)
{
    QFormLayout* layoutVue = new QFormLayout();
    QHBoxLayout* layoutVehicule = new QHBoxLayout();

    btnVoiture = new QRadioButton("voiture");
    btnVelo = new QRadioButton("vélo");
    btnBus = new QRadioButton("bus");
    layoutVehicule->addWidget(btnVoiture);
    layoutVehicule->addWidget(btnVelo);
    layoutVehicule->addWidget(btnBus);


    lineImmatriculation = new QLineEdit();
    lineModele = new QLineEdit();
    lineNbPlaces = new QLineEdit();
    btnConfirmer = new QPushButton("confirmer");

    layoutVue->addRow(layoutVehicule);
    layoutVue->addRow("immatriculation", lineImmatriculation);
    layoutVue->addRow("modèle", lineModele);
    layoutVue->addRow("nombre de places", lineNbPlaces);
    layoutVue->addRow(btnConfirmer);

    setLayout(layoutVue);

    QObject::connect(btnConfirmer, SIGNAL(clicked()), this, SLOT(ajouter()));
    QObject::connect(btnVelo, SIGNAL(clicked()), this, SLOT(casVelo()));
    QObject::connect(btnVoiture, SIGNAL(clicked()), this, SLOT(casVehicule()));
    QObject::connect(btnBus, SIGNAL(clicked()), this, SLOT(casVehicule()));


    garage->ajouterVue(*this);
}


void VueAjouterVehicule::ajouter(){
    if(btnVoiture->isChecked()){
        Voiture *v = new Voiture(lineNbPlaces->text().toInt(), lineImmatriculation->text(), lineModele->text());

        garage->ajouterVoiture(v);
    }else if(btnVelo->isChecked()){
        Velo *v = new Velo(lineNbPlaces->text().toInt(), lineModele->text());

        garage->ajouterVelo(v);
    }else if(btnBus->isChecked()){
        Bus *v = new Bus(lineNbPlaces->text().toInt(), lineImmatriculation->text(), lineModele->text());
        garage->ajouterBus(v);
    }

    garage->setCasUtilisation(Garage::VOIR_NUM_VEHICULE);

}

void VueAjouterVehicule::casVelo(){
    lineImmatriculation->setEnabled(false);
}

void VueAjouterVehicule::casVehicule(){
    lineImmatriculation->setEnabled(true);
}

void VueAjouterVehicule::maj(){
}






//vue afficher num véhicule//////////////////////////////////////////////



void VueAfficherNumVehicule::maj(){
    setIdentifiant(garage->getVehiculeActu().identifiant());
}

