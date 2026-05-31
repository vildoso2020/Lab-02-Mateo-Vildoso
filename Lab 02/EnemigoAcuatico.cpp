// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAcuatico.h"
#include "Components/StaticMeshComponent.h"

AEnemigoAcuatico::AEnemigoAcuatico()
{
	MeshEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshEnemigo"));
	RootComponent = MeshEnemigo;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}
}
