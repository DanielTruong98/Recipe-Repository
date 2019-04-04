#include "RecipeList.h"

//Declaration
RecipeList::RecipeList(){
  currentplace = 0;
  current = new Recipe();
  front = current;
  back = current;
}


//setters
void RecipeList::addRecipe(){
    std::string rName;
    int cTime;
    int pTime;
    bool ingredientInput = false;

    std::string input;

    std::cout << "Input recipe name: ";
    std::getline (std::cin, rName);
    std::cout << std::endl;

    std::cout << "Input cooking time: ";
    std::cin >> cTime;
    std::cout << std::endl;

    std::cout << "Input preparation time: ";
    std::cin >> pTime;
    std::cout << std::endl;

    current->setRecipeName(rName);
    current->setCookingTime(cTime);
    current->setPreparationTime(pTime);

    std::cout << "Input ingredient name with amount and unit after a :\n";
    std::cout << "Example: water:10ml\n";
    std::cout << "When finished inputting ingredients, type exit to leave ingredient input\n";

    while(ingredientInput == false){
      char c = ':';
      std::getline(std::cin, input);
      if (input != "exit"){
        size_t location = input.find(c);
        std::string tempName = input.substr(0, location);
        std::string tempAmount = input.substr(location + 1, input.size() - location);
        current->addIngredient(tempName);
        current->addIngredientAmount(tempAmount);
      }
      else{
        ingredientInput = true;
      }
    }
}

//getters
int RecipeList::recipeAmount(){
  return listRecipe.size();
}

Recipe* RecipeList::getCurrentRecipe(){
  return current;
}

int RecipeList::findCurrentSpot(int val){

}

Recipe* RecipeList::findRecipe(std::string rName){
  if (current->getRecipeName() == rName){
    std::cout << rName << " found in list\n";
  }
  else{
    std::cout << rName << " not found in list\n";
  }
}
