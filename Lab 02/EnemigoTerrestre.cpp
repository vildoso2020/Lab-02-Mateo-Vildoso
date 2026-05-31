// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoTerrestre.h"
#include "Components/StaticMeshComponent.h"

AEnemigoTerrestre::AEnemigoTerrestre()
{
	MeshEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshEnemigo"));
	RootComponent = MeshEnemigo;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}
}
