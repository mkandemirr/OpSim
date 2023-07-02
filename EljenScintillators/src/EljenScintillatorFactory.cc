#include "EljenScintillatorFactory.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"

#include "EJ200Builder.hh"
#include "EJ260Builder.hh"
#include "EJ426Builder.hh"
#include "EJ335Builder.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EljenScintillatorFactory* EljenScintillatorFactory::fInstance = nullptr;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EljenScintillatorFactory::EljenScintillatorFactory():
VMaterialFactory(),
fEJ200Builder{nullptr},
fEJ260Builder{nullptr},
fEJ426Builder{nullptr},
fEJ335Builder{nullptr}
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EljenScintillatorFactory::~EljenScintillatorFactory()
{	
  if(fEJ200Builder)   delete fEJ200Builder;
  if(fEJ260Builder)   delete fEJ260Builder;
  if(fEJ426Builder)   delete fEJ426Builder;
  if(fEJ335Builder)   delete fEJ335Builder;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Material* EljenScintillatorFactory::CreateMaterial(const G4String& name, G4bool enableOpticalProperty)
{
  G4Material* mat = G4NistManager::Instance()->FindOrBuildMaterial(name);
  if(mat) return mat;

  if(name=="EJ-200" && !fEJ200Builder)
  {
    fEJ200Builder = new EJ200Builder(enableOpticalProperty);
    return fEJ200Builder->GetProduct();
  }else if(name=="EJ-260" && !fEJ260Builder)
  {
    fEJ260Builder = new EJ260Builder(name);
    return fEJ260Builder->GetProduct();
  }else if(name=="EJ-426" && !fEJ426Builder)
  {
    fEJ426Builder = new EJ426Builder(enableOpticalProperty);
    return fEJ426Builder->GetProduct();
  }else if(name=="EJ-335" && !fEJ335Builder)
  {
    fEJ335Builder = new EJ335Builder(enableOpticalProperty);
    return fEJ335Builder->GetProduct();
  }else
  {
    return nullptr;
  }
   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EljenScintillatorFactory* EljenScintillatorFactory::GetInstance()
{
  static EljenScintillatorFactory instance;
  
  if(fInstance == nullptr)
  {
    fInstance = &instance;
  }
    
  return fInstance;
   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

