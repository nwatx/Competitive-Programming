# for i in range(0, 64):
# 	print(f"""MODIFIED_ARRAY[{i}] = rc.readSharedArray({i});
# 	CURRENT_ARRAY[{i}] = rc.readSharedArray({i});""")

for i in range(0, 6):
	# print(f"""if(MODIFIED_ARRAY[{i}] != CURRENT_ARRAY[{i}]) {{ rc.writeSharedArray({i}, MODIFIED_ARRAY[{i}]); }}""")
	print(f"""if((currentRow & ((1 << 8) << {i})) != 0){{ bs1 |= (1 << {i}); }} if((currentRow & (1 << {i})) != 0) {{ bs2 |= 1 << {i}; }}""")