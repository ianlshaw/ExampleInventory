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
	CollisionSphereComp->OnComponentEndOverlap.AddDynamic(this, &AItem::onEndOverlap);
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
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("AItem::onOverlap")));

	AExampleInventoryCharacter* EIC = Cast<AExampleInventoryCharacter>(OtherActor);
	if (EIC != nullptr) {
		EIC->NearbyInventory.Add(GetClass());
		UUserWidget* inventory_as_user_widget = EIC->InventoryWidgetReference;
		UInventoryWidget* inventory_widget_reference = Cast<UInventoryWidget>(inventory_as_user_widget);
		inventory_widget_reference->DrawInventory();

		EIC->OverlappingItems.Add(this);
	}
}

void AItem::onEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("AItem::onEndOverlap")));

	// Create a pointer to the player character
	AExampleInventoryCharacter* EIC = Cast<AExampleInventoryCharacter>(OtherActor);

	// Ensure the pointer is not null
	if (EIC != nullptr) {
		int item_index = EIC->NearbyInventory.FindLast(GetClass());
		
		EIC->NearbyInventory.RemoveAt(item_index);
		EIC->OverlappingItems.RemoveAt(item_index);

		UUserWidget* inventory_as_user_widget = EIC->InventoryWidgetReference;
		UInventoryWidget* inventory_widget_reference = Cast<UInventoryWidget>(inventory_as_user_widget);
		UE_LOG(LogTemp, Warning, TEXT("item_index is: %d"), item_index);
		//inventory_widget_reference->GP_NearbyInventory->RemoveChildAt(item_index);
		inventory_widget_reference->GP_NearbyInventory->ClearChildren();
		inventory_widget_reference->DrawInventory();

	
	}
}