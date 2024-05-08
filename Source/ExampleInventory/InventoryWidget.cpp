// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "InventorySlotWidget.h"
#include "ExampleInventoryCharacter.h"
#include "Item.h"

UInventoryWidget::UInventoryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hi from UInventoryWidget constructor")));

	// You can give the TSubclassOf variable a default class to use like this.
	InventorySlotWidgetClass = UInventorySlotWidget::StaticClass();
}

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hi from UInventoryWidget::construct")));
	DrawInventory();
}

void UInventoryWidget::DrawInventory()
{
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hi from UInventoryWidget::DrawInventory")));

	APawn* owning_player_pawn = GetOwningPlayerPawn();
	AExampleInventoryCharacter* EIC = Cast<AExampleInventoryCharacter>(owning_player_pawn);


	for (int32 Index = 0; Index != EIC->Inventory.Num(); ++Index)
	{
	
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("inside inventory loop")));
	
		//each_slot_widget.Name = item.Name;
		UUserWidget* slot_widget = CreateWidget(GetOwningPlayer(), InventorySlotWidgetClass);

		
		GP_Inventory->AddChildToUniformGrid(slot_widget, Index, 0);

		//UE_LOG(LogTemp, Warning, TEXT("The integer value is: %d"), Index);

	}

	for (int32 Index = 0; Index != EIC->NearbyInventory.Num(); ++Index)
	{
		UUserWidget* slot_widget = CreateWidget(GetOwningPlayer(), InventorySlotWidgetClass);
		GP_NearbyInventory->AddChildToUniformGrid(slot_widget, Index, 0);
	}

}