// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"

// Sets default values
AEnemigo::AEnemigo()
{
	PrimaryActorTick.bCanEverTick = true;
	IndicePuntoRutaActual = 0;
}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();

	CargarRutas();

	GetWorldTimerManager().SetTimer(TimerDesaparicion, this, &AEnemigo::Desaparecer, TiempoVida, false);
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Mover(DeltaTime);

}

void AEnemigo::CargarRutas()
{
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	// Agregar punto inicial
	PuntosRuta.Add(PosicionInicial);

	// Generar 10 waypoints aleatorios
	for (int32 i = 0; i < 10; i++)
	{
		float X = FMath::RandRange(WorldLimitesMin.X, WorldLimitesMax.X);
		float Y = FMath::RandRange(WorldLimitesMin.Y, WorldLimitesMax.Y);
		FVector NuevoPuntoRuta(X, Y, PosicionInicial.Z);
		PuntosRuta.Add(NuevoPuntoRuta);
	}

	IndicePuntoRutaActual = 1;
}


void AEnemigo::Desaparecer()
{
	Destroy();
}

void AEnemigo::Mover(float DeltaTime)
{
	if (PuntosRuta.Num() == 0)
	{
		return;
	}

	FVector PosActual = GetActorLocation();
	FVector PosDestino = PuntosRuta[IndicePuntoRutaActual];

	float Distancia = FVector::Dist(PosActual, PosDestino);

	if (Distancia <= ToleranciaLlegada)
	{
		IndicePuntoRutaActual++;

		if (IndicePuntoRutaActual >= PuntosRuta.Num())
		{
			CargarRutas();
		}
		return;
	}

	FVector Direccion = (PosDestino - PosActual).GetSafeNormal();
	FVector NuevaPosicion = PosActual + Direccion * VelocidadMovimiento * DeltaTime;

	SetActorLocation(NuevaPosicion);
}
