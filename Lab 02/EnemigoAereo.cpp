// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereo.h"
#include "Components/StaticMeshComponent.h"

AEnemigoAereo::AEnemigoAereo()
{
	MeshEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshEnemigo"));
	RootComponent = MeshEnemigo;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}
}
