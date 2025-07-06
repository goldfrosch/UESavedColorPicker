#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

DECLARE_DELEGATE_OneParam(FOnColorPickerEditorInputTextChangedDelegate
						, const FString&);

DECLARE_DELEGATE_OneParam(FOnColorPickerEditorInputCommitDelegate
						, const FString&);

class SAVEDCOLORPICKER_API SColorPickerEditorInput : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SColorPickerEditorInput)
		{
		}

		SLATE_EVENT(FOnColorPickerEditorInputTextChangedDelegate, OnTextChanged)
		SLATE_EVENT(FOnColorPickerEditorInputCommitDelegate, OnCommitted)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	TSharedPtr<STextBlock> CategoryTitleTextBlock;
	TSharedPtr<SEditableTextBox> CategoryEditTitleBlock;

	FOnColorPickerEditorInputTextChangedDelegate OnTextChanged;
	FOnColorPickerEditorInputCommitDelegate OnCommitted;

	FString CurrentCategoryTitle;
	TArray<FString> CurrentCategoryList;

	void HandleTextChanged(const FText& NewText);
	void HandleTextCommitted(const FText& Text, ETextCommit::Type CommitType);

	bool AddCategoryTitle_Internal(const FString& TextValue);
};
