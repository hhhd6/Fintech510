# def money_spent(data):
#     spending_dic = {}
#     for game in data:
#         name = game[1]
#         money = float(game[2]) # 要把string的数据转换成float
        
#         if name in spending_dic:
#             spending_dic[name] += money
#         else:
#             spending_dic[name] = money
#     return spending_dic # 返回的值一定是你想要的值

# def howMuchSpent(data):
#     spending_dict = {}  # 初始化一个空字典来存储每个玩家的花费总额
    
#     for game in data:
#         name = game[1]  # 获取玩家的名字
#         cost = float(game[2])  # 获取游戏的花费并转换为浮点数
        
#         # 如果玩家已经在字典中，则累加他们的花费；否则，初始化他们的花费
#         if name in spending_dict:
#             spending_dict[name] += cost
#         else:
#             spending_dict[name] = cost
    
#     return spending_dict

# def dictNamesToListAnimals(data):
#     animals_dic = {}
#     for game in data:
#         name = game[1]
        
#         if len(game) == 3:
#             animals = " "
#         else:
#             animals = game[-1]
            
#         animals_dic[name] = animals
    
#     return animals_dic

def dictNamesToListAnimals(data):
    animal_dict = {}  # 初始化一个空字典来存储玩家和他们赢得的动物
    
    for game in data:
        # 检查游戏结果是否是 'won'
        if game[3] == "won":
            name = game[1]  # 获取玩家名字
            animal = game[4]  # 获取赢得的动物
            
            # 如果玩家已经在字典中，添加动物；如果不在字典中，初始化动物列表
            if name in animal_dict:
                # 只添加独特的动物
                if animal not in animal_dict[name]:
                    animal_dict[name].append(animal)
            else:
                animal_dict[name] = [animal]  # 初始化玩家的动物列表
    
    return animal_dict # 返回包含玩家和独特动物的字典
            
            

data = [ ["ringtoss", "jackson", "3.00", "lost"],
["darts", "xiaobai", "2.00", "won", "dog"],
["basketball", "jackson", "3.00", "lost"],
["ringtoss", "kim", "3.00", "lost"],
["ringtoss", "sarah", "2.00", "won", "cat"],
["bingo", "brett", "2.00", "won", "camel"],
["darts", "hattie", "2.00", "lost"],
["ladderclimb", "jackson", "2.00", "lost"],
["ringtoss", "xiaobai", "3.00", "won", "cat"],
["bingo", "hattie", "2.00", "lost"],
["platebreak", "sarah", "3.00", "lost"],
["darts", "hattie", "2.00", "won", "dog"],
["basketball", "sarah", "3.00", "won", "cat"],
["ringtoss", "xiaobai", "3.00", "won", "turtle"],
["ringtoss", "jackson", "3.00", "won", "pikachu"],
["platebreak", "jackson", "3.00", "lost"],
["darts", "sarah", "2.00", "won", "camel"],
["bingo", "brett", "2.00", "won", "cat"] ]

print(dictNamesToListAnimals(data))