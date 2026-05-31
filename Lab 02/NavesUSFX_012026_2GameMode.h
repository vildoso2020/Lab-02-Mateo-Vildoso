// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Enemigo.h"
#include "NavesUSFX_012026_2GameMode.generated.h"

UCLASS(MinimalAPI)
class ANavesUSFX_012026_2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANavesUSFX_012026_2GameMode();

protected:
	virtual void BeginPlay() override;

private:
	// Contenedor de la primera cuadrilla
	TArray<AEnemigo*> Cuadrilla1;

	// Contenedor de la segunda cuadrilla
	TArray<AEnemigo*> Cuadrilla2;

	// Timer que verifica periodicamente si la Cuadrilla1 fue eliminada
	FTimerHandle TimerVerificarCuadrilla;

	bool bCuadrilla2Spawneada;

	void SpawnCuadrilla1();
	void SpawnCuadrilla2();

	// Se llama cada segundo para verificar si todos los de C1 desaparecieron
	void VerificarCuadrilla1();

	// Funcion auxiliar para spawnear un enemigo de cualquier subclase
	AEnemigo* SpawnEnemigo(TSubclassOf<AEnemigo> ClaseEnemigo, FVector Posicion);
};
