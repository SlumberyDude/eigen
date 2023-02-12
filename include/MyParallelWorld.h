//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file RE06/include/RE06ParallelWorld.hh
/// \brief Definition of the RE06ParallelWorld class
//
// 

#ifndef MyParallelWorld_h
#define MyParallelWorld_h 1

#include "G4VUserParallelWorld.hh"
#include "globals.hh"
#include <vector>

class G4LogicalVolume;
class G4VPhysicalVolume;

class MyParallelWorld : public G4VUserParallelWorld
{
  public:
    MyParallelWorld(G4String worldName);
    virtual ~MyParallelWorld();

    virtual void Construct();
    virtual void ConstructSD();
  
//    void SetSerialGeometry(G4bool ser);
//    G4bool IsSerial() const { return fSerial; }

  private:
    void SetupGeometry();
    void SetupDetectors();
     
    G4bool             fConstructed;
    static G4ThreadLocal G4bool fSDConstructed;
//    std::vector<G4LogicalVolume*> m_logVolumes;
    G4LogicalVolume* m_detLog;
    G4LogicalVolume* m_windowLogic;
    G4LogicalVolume* m_testLogic;

};


#endif

