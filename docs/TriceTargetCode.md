# TRICE Target Code Implementation

## TRICE Macro structure

### `TRICE_ENTER`

- Optionally disable interrupts.
- Prepare `TriceBufferWritePosition` and keep its initial value.

### `TRICE_PUT`

- Use and increment `TriceBufferWritePosition`.

### `TRICE_LEAVE`

- Use `TriceBufferWritePosition` and its initial value for data transfer
- Optionally restore interrupt state.

## `TRICE_STACK_BUFFER`

- `TRICE_ENTER`: Allocate stack
- `TRICE_LEAVE`: Call TriceDirectOut()

## `TRICE_STATIC_BUFFER`

- This is like `TRICE_STACK_BUFFER` but avoids stack allocation, what is better for many stacks.
- `TRICE_ENTER`: Set TriceBufferWritePosition to buffer start.
- `TRICE_LEAVE`: Call TriceDirectOut().

## `TRICE_DOUBLE_BUFFER`

- `TRICE_ENTER`: Keep TriceBufferWritePosition.
- `TRICE_LEAVE`: Optionally call TriceDirectOut().

## `TRICE_RING_BUFFER`

- `TRICE_ENTER`: Keep or wrap TriceBufferWritePosition and add offset.
- `TRICE_LEAVE`: Optionally call TriceDirectOut().

The `TRICE_RING_BUFFER` allocates incremental ring buffer space and each trice location is read by a deferred task.

## Deferred Out

### Double Buffer

- TriceTransfer
  - TriceOut
  - TriceNonBlockingWrite( triceID, enc, encLen );
  
### Ring Buffer

- TriceTransfer
  - lastWordCount = TriceSingleDeferredOut(addr);
    - int triceID = TriceIDAndBuffer( pData, &wordCount, &pStart, &Length );
    - TriceNonBlockingWrite( triceID, pEnc, encLen );

## Direct Transfer

- TRICE_LEAVE
  - TriceDirectWrite(triceSingleBufferStartWritePosition, wordCount);
    - optional RTT32 with optional XTEAwithCOBS
    - optional RTT8  with optional XTEAwithCOBS
    - optional
      - triceIDAndLen
      - triceDirectEncode
      - triceNonBlockingDirectWrite
