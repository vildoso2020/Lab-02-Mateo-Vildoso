// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

UCLASS()
class NAVESUSFX_012026_2_API AEnemigo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemigo();

	// Componente visual del enemigo
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshEnemigo;

	float VelocidadMovimiento = 100.0f;

	float ToleranciaLlegada = 50.0f;

	FVector WorldLimitesMin = FVector(-1000.0f, -1000.0f, 0.0f);

	FVector WorldLimitesMax = FVector(1000.0f, 1000.0f, 0.0f);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// Tiempo en segundos antes de que el enemigo desaparezca
	UPROPERTY(EditAnywhere)
	float TiempoVida = 15.0f;

private:
	FVector PosicionInicial;

	// Lista de waypoints generados aleatoriamente
	TArray<FVector> PuntosRuta;

	// Indice del waypoint destino actual
	int32 IndicePuntoRutaActual;

	// Timer que controla la desaparicion del enemigo
	FTimerHandle TimerDesaparicion;

	// Genera waypoints aleatorios dentro del area de patrulla
	void CargarRutas();

	// Desplaza el enemigo hacia el waypoint actual
	void Mover(float DeltaTime);

	// Destruye el actor al cumplirse TiempoVida
	void Desaparecer();

};
