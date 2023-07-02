#include "EJ335Builder.hh"
#include "G4Material.hh"
#include "MaterialPropertiesTable.hh"
#include "G4UImanager.hh"
#include "G4NistManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EJ335Builder::EJ335Builder(G4bool enableOpticalProperty):
VMaterialBuilder(enableOpticalProperty) 
{
  if(IsOpticalPropertyEnabled())
  {
    pMatPropTable = new MaterialPropertiesTable("EJ-335"); 
    
    G4UImanager* uImanager = G4UImanager::GetUIpointer();
    uImanager->ApplyCommand("/control/execute EljenScintillators/macros/ej-335.mac");  
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EJ335Builder::~EJ335Builder()
{ 
  if(pMatPropTable) 
  {
  	delete pMatPropTable;
  	pMatPropTable = nullptr;
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


G4Material* EJ335Builder::Build()          
{ 
  //https://eljentechnology.com/images/products/data_sheets/EJ-331_EJ-335.pdf
	
	G4double hydrogenAtomDensity 	= 6.16e+22*(1./cm3);
	//G4double carbonAtomDensity 	= 3.93e+22*(1./cm3;
  
  G4double hydrogenMolarMass    = pNistManager->FindOrBuildElement("H")->GetAtomicMassAmu()*(g/mole);
  
  G4double hydrogenMassDensity  = (hydrogenAtomDensity/CLHEP::Avogadro)*hydrogenMolarMass;

	G4double density 							= 0.89*g/cm3;
	
	G4double hydrogenMassFraction = hydrogenMassDensity/density;
	G4double gdMassFraction       = 0.25*perCent;
	G4double carbonMassFraction   = 1-gdMassFraction-hydrogenMassFraction;
 
  /*
  //validity of atom density
  G4cout<<"hydrogen atom density: "<<
  (density*hydrogenMassFraction/hydrogenMolarMass)*CLHEP::Avogadro*cm3<<" (1/cm3)"<<G4endl;
  
  G4double carbonMolarMass      = pNistManager->FindOrBuildElement("C")->GetAtomicMassAmu()*(g/mole);
  
  G4cout<<"carbon atom density: "<<
  (density*carbonMassFraction/carbonMolarMass)*CLHEP::Avogadro*cm3<<" (1/cm3)"<<G4endl;
  //carbon atom density is obtained as expected.
  */

	G4Material *scin_mat = new G4Material("EJ-335", density, 3);
	scin_mat->AddElement(pNistManager->FindOrBuildElement("H"), hydrogenMassFraction);
	scin_mat->AddElement(pNistManager->FindOrBuildElement("C"), carbonMassFraction);
	scin_mat->AddElement(pNistManager->FindOrBuildElement("Gd"), gdMassFraction);
  
  return scin_mat;  
}

