import json

print()
print('Welcome to LoRa_GPIO configuration')
print('-' * 20)
mesh_count = int(input('How many meshes are in your project?: '))
print('{} meshes'.format(mesh_count))
meshes = []

for mesh in range(mesh_count):
    nodes = []
    node_count = int(input('how many nodes in mesh #{}?: '.format(mesh + 1)))
    for node in range(node_count):
        node_name = input('please name node {}: '.format(node + 1))
        pins = []
        pin_count = int(input('how many I/O pins on node {}?: '.format(node_name)))
        for pin in range(pin_count):
            pin_no = int(input('enter next pin number'))
            pins.append(pin_no)
        key = {node_name : pins}
        nodes.append(key)
    meshes.append(nodes)
    #del nodes

# file_name = input('Please name your output file: ')
# out_file = file_name + '.json'
out_file = 'loragpioconfig.json'

with open(out_file, 'w') as f:
    json.dump(meshes, f)

print()
print('configuration complete')
print()
