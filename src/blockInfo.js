import { ApiPromise, WsProvider } from '@polkadot/api';
import 'regenerator-runtime/runtime';

async function getBlockInfo({hash, number}) {
    const wsProvider = new WsProvider('wss://rpc.polkadot.io');
    const api = await ApiPromise.create({ provider: wsProvider });

    const chain = await api.rpc.system.chain();

    let header;

    if (hash != "") {
        header = await api.rpc.chain.getHeader(hash);
    } else if (number != "") {
        number = number.replaceAll(",", " ");
        hash = await api.rpc.chain.getBlockHash(number);
        header = await api.rpc.chain.getHeader(hash);
    } else {
        header = await api.rpc.chain.getHeader();
    }
    
    const blockInfo = {
        chain: chain.toHuman(),
        blockNumber: header.number.toHuman(),
        blockHash: header.hash.toHuman(),
        stateRoot: header.stateRoot.toHuman(),
        extrinsicsRoot: header.extrinsicsRoot.toHuman(),
        parentHash: header.parentHash.toHuman()
    }

    return blockInfo;
}

export {getBlockInfo};