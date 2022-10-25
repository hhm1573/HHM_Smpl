#pragma once

#include "CoreMinimal.h"
#include "Data/Inventory/HHM_Inventory.h"

#include "Data/Item/ItemData/HHM_ItemData.h"

#include "HHM_Inventory_List.generated.h"



UCLASS()
class UHHM_Inventory_List : public UHHM_Inventory
{
	GENERATED_BODY()

public:
	UHHM_Inventory_List();

private:
	UPROPERTY()		//������ �����͸� ID�� �Բ� map�� ������.
		TMap<int32, UHHM_ItemData*>		m_Container_ItemData;
	UPROPERTY()		//�������� ID�� �迭�� �����Ͽ� ����Ʈ ������ ������ �ʰ� ��.
		TArray<int32>					m_Container_ItemDataIndex;



public:
	UFUNCTION(BlueprintCallable)
		bool	BP_Initialize_Inventory(FString _name_Inventory, float _time_Interact, int32 _size_Inventory);
	UFUNCTION(BlueprintCallable)
		bool	BP_Set_InventorySize(int32 _size);

	UFUNCTION(BlueprintCallable)
		int32						BP_Get_InventorySize();
	UFUNCTION(BlueprintCallable)
		TArray<UHHM_ItemData*>		BP_Get_ItemList();
	UFUNCTION(Blueprintcallable, Category = HHM_Inventory_List)
		int32						BP_Get_NumItem();

	UFUNCTION(BlueprintCallable)
		EHHM_InventoryReturn	BP_Item_Insert(int32& _index_Return, UHHM_ItemData* _pItemData);
	UFUNCTION(BlueprintCallable)
		EHHM_InventoryReturn	BP_Item_Pop_At(UHHM_ItemData*& _pItemData_Return, int32 _index);
	UFUNCTION(BlueprintCallable)
		EHHM_InventoryReturn	BP_Item_Remove(UHHM_ItemData* _pItemData);
		
	UFUNCTION(BlueprintCallable)
		void					BP_Clear_Inventory();

	

public:
	bool	Initialize_Inventory(FString _name_Inventory, float _time_Interact, int32 _size_Inventory);
	bool	Set_InventorySize(int32 _size);

public:
	int32								Get_InventorySize() const;
	bool								IsInventoryFull() const;
	int32								Get_ItemNum() const;
	UHHM_ItemData*						Get_Item(int32 _index);
	const TMap<int32, UHHM_ItemData*>*	Get_ItemContainer_Const() const;
	TArray<UHHM_ItemData*>				Get_ItemList_Const() const;

public:
	EHHM_InventoryReturn	Item_Insert(int32& _index_Return, UHHM_ItemData* _pItemData);
	EHHM_InventoryReturn	Item_Pop_At(UHHM_ItemData*& _pItemData_Return, int32 _index);
	EHHM_InventoryReturn	Item_Remove(UHHM_ItemData* _pItemData);

	void					Clear_Inventory();



private:
	int32					Get_AvailiableItemID();
};