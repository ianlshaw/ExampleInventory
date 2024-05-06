// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "ExampleInventoryCharacter.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	RootComponent = MeshComp;

	MeshComp->SetSimulatePhysics(true);

	CollisionSphereComp = CreateDefaultSubobject<USphereComponent>("SphereCollider");

	CollisionSphereComp->OnComponentBeginOverlap.AddDynamic(this, &AItem::onOverlap);

	CollisionSphereComp->SetupAttachment(MeshComp);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::onOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AExampleInventoryCharacter* EIC = Cast<AExampleInventoryCharacter>(OtherActor);
	if (EIC != nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Found AExampleInventoryCharacter")));
	}
	
}

