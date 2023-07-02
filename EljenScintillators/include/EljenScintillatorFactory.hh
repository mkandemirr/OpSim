#ifndef EljenScintillatorFactory_h
#define EljenScintillatorFactory_h 1

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "VMaterialFactory.hh"

class VMaterialBuilder;
class G4Material;

//singleton class
class EljenScintillatorFactory: public VMaterialFactory
{
  public:
    static EljenScintillatorFactory* GetInstance();
    
    //Singletons should not be cloneable.
    EljenScintillatorFactory(const EljenScintillatorFactory&) = delete;
    
    //Singletons should not be assignable.
    EljenScintillatorFactory& operator=(const EljenScintillatorFactory&) = delete;
       
  protected:  
    EljenScintillatorFactory();
    virtual ~EljenScintillatorFactory();
      
    virtual G4Material* CreateMaterial(const G4String& name, G4bool enableOpticalProperty) override;
      
  private:
    static EljenScintillatorFactory* fInstance;  
 
    VMaterialBuilder* fEJ200Builder; 
    VMaterialBuilder* fEJ260Builder;
    VMaterialBuilder* fEJ426Builder;
    VMaterialBuilder* fEJ335Builder;                  
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif 
