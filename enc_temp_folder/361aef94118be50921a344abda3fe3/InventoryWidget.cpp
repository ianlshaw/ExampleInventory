// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hi from UInventoryWidget::construct")));
	//APawn* owning_player_pawn = GetOwningPlayerPawn();
	//AExampleInventoryCharacter* EIC = Cast<AExampleInventoryCharacter>(owning_player_pawn);
}
