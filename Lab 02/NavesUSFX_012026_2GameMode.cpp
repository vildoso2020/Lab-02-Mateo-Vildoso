// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesUSFX_012026_2GameMode.h"
#include "NavesUSFX_012026_2Pawn.h"

// Clases hijas aereas
#include "EAHelicoptero.h"
#include "EAAvion.h"
#include "EADron.h"

// Clases hijas terrestres
#include "ETSoldado.h"
#include "ETTanque.h"
#include "ETCamion.h"

// Clases hijas acuaticas
#include "EABarco.h"
#include "EALancha.h"
#include "EAMotoAcuatica.h"

ANavesUSFX_012026_2GameMode::ANavesUSFX_012026_2GameMode()
{
	DefaultPawnClass = ANavesUSFX_012026_2Pawn::StaticClass();
	bCuadrilla2Spawneada = false;
}

void ANavesUSFX_012026_2GameMode::BeginPlay()
{
	Super::BeginPlay();

	SpawnCuadrilla1();

	// Verificar cada segundo si la Cuadrilla1 fue eliminada
	GetWorldTimerManager().SetTimer(
		TimerVerificarCuadrilla,
		this,
		&ANavesUSFX_012026_2GameMode::VerificarCuadrilla1,
		1.0f,
		true
	);
}

AEnemigo* ANavesUSFX_012026_2GameMode::SpawnEnemigo(TSubclassOf<AEnemigo> ClaseEnemigo, FVector Posicion)
{
	UWorld* World = GetWorld();
	if (!World) return nullptr;

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	return World->SpawnActor<AEnemigo>(ClaseEnemigo, Posicion, FRotator::ZeroRotator, Params);
}

void ANavesUSFX_012026_2GameMode::SpawnCuadrilla1()
{
	Cuadrilla1.Add(SpawnEnemigo(AEAHelicoptero::StaticClass(), FVector( 500.f,  200.f, 500.f)));
	Cuadrilla1.Add(SpawnEnemigo(AEAAvion::StaticClass(),       FVector( 500.f,    0.f, 600.f)));
	Cuadrilla1.Add(SpawnEnemigo(AEADron::StaticClass(),        FVector( 500.f, -200.f, 400.f)));

	Cuadrilla1.Add(SpawnEnemigo(AETSoldado::StaticClass(), FVector(0.f,  200.f, 250.f)));
	Cuadrilla1.Add(SpawnEnemigo(AETTanque::StaticClass(),  FVector(0.f,    0.f, 250.f)));
	Cuadrilla1.Add(SpawnEnemigo(AETCamion::StaticClass(),  FVector(0.f, -200.f, 250.f)));

	Cuadrilla1.Add(SpawnEnemigo(AEABarco::StaticClass(),        FVector(-500.f,  200.f, 200.f)));
	Cuadrilla1.Add(SpawnEnemigo(AEALancha::StaticClass(),       FVector(-500.f,   200.f, 200.f)));
	Cuadrilla1.Add(SpawnEnemigo(AEAMotoAcuatica::StaticClass(), FVector(-500.f, 200.f, 200.f)));
}

void ANavesUSFX_012026_2GameMode::SpawnCuadrilla2()
{
	Cuadrilla2.Add(SpawnEnemigo(AEAHelicoptero::StaticClass(), FVector( 2500.f,  200.f, 500.f)));
	Cuadrilla2.Add(SpawnEnemigo(AEAAvion::StaticClass(),       FVector( 2500.f,    0.f, 600.f)));
	Cuadrilla2.Add(SpawnEnemigo(AEADron::StaticClass(),        FVector( 2500.f, -200.f, 400.f)));

	Cuadrilla2.Add(SpawnEnemigo(AETSoldado::StaticClass(), FVector(2000.f,  200.f, 200.f)));
	Cuadrilla2.Add(SpawnEnemigo(AETTanque::StaticClass(),  FVector(2000.f,    0.f, 200.f)));
	Cuadrilla2.Add(SpawnEnemigo(AETCamion::StaticClass(),  FVector(2000.f, -200.f, 200.f)));

	Cuadrilla2.Add(SpawnEnemigo(AEABarco::StaticClass(),        FVector(1500.f,  200.f, 200.f)));
	Cuadrilla2.Add(SpawnEnemigo(AEALancha::StaticClass(),       FVector(1500.f,    0.f, 200.f)));
	Cuadrilla2.Add(SpawnEnemigo(AEAMotoAcuatica::StaticClass(), FVector(1500.f, -200.f, 200.f)));
}

void ANavesUSFX_012026_2GameMode::VerificarCuadrilla1()
{
	if (bCuadrilla2Spawneada || Cuadrilla1.Num() == 0) return;

	for (AEnemigo* E : Cuadrilla1)
	{
		if (IsValid(E))
		{
			return; 
		}
	}

	// Todos los miembros de Cuadrilla1 desaparecieron
	GetWorldTimerManager().ClearTimer(TimerVerificarCuadrilla);
	SpawnCuadrilla2();
	bCuadrilla2Spawneada = true;
}
