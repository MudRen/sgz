mixed bat_message()
{
	return
([		0:
	      ([
			  "attack": ({
					"$n提起拳头向$T的xx捶去。",
					"$n照准$T的xx猛地就是一拳。",
					"$n挥拳攻击$T的xx。",
					"$n朝$T的xx一抓。",
						}),
				"hit":  ({
					"结果只是稍稍碰到，比蚊子叮还轻。",
					"结果好象只是替$T掸了掸灰尘。",
					"结果正中$T的xx。"
						}),
				"dodge": ({
						"$T急忙一闪身，避开了$n的攻击。",
						"$T身子一侧，总算躲过了$n的攻击。",
					}),
				"dodge-on-horse": ({
					"$T用力一扯马缰，跨下$o3猛地一跳，闪过了$n的攻击。",
					"$T连忙一夹马腹，$o3负痛一个转身，避开了去。",
					"$T慌忙弯腰，伏在马背上，躲过了$n的攻击。",
					"$T急忙一个侧身闪开，却差点跌下马去。",
						}),
				"miss": ({
					"结果连$T的衣角都没有沾到。",
					"结果跟$T的xx偏了几寸。",
					}),
				"wait": ({
					"$n缓缓移动着脚步，伺机出手。",
					"$n目不转睛地盯住$T，准备寻找对方的破绽出手。",
					}),
				"wait-on-horse" :({
					"$n一手紧紧攥住马缰，等待着机会发动攻击。",
					"$n双腿一夹，策动跨下$o2，伺机出手。",
					}),
				"parry": ({
					"结果被$T格开了。",
					"但是被$T挡开了。",
					}),
		  ]),
]);
}
