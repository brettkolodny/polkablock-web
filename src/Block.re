type blockInfo = {
    chain: string,
    blockNumber: string,
    blockHash: string,
    stateRoot: string,
    extrinsicsRoot: string,
    parentHash: string
};

[@react.component]
let make = (~blockInfo) => {
    <div id="block">
        <div className="info">
            {React.string(blockInfo.blockHash)}
            <div>{React.string("hash")}</div>
        </div>

        <div className="info">
            {React.string(blockInfo.blockNumber)}
            <div>{React.string("Block number")}</div>
        </div>

        <div className="info">
            {React.string(blockInfo.stateRoot)}
            <div>{React.string("State root")}</div>
        </div>

        <div className="info">
            {React.string(blockInfo.extrinsicsRoot)}
            <div>{React.string("Extrinsics root")}</div>
        </div>

        <div className="info">
            {React.string(blockInfo.parentHash)}
            <div>{React.string("Parent hash")}</div>
        </div>
    </div>
};