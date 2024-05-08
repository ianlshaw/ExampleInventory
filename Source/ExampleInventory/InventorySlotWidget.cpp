// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlotWidget.h"

UInventorySlotWidget::UInventorySlotWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonIcon->OnClicked.AddDynamic(this, &UInventorySlotWidget::OnClick);
    ButtonText->OnClicked.AddDynamic(this, &UInventorySlotWidget::OnClick);
}


void UInventorySlotWidget::OnClick()
{
	UE_LOG(LogTemp, Warning, TEXT("Click"));
}
